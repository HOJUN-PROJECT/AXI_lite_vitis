<img width="1046" height="676" alt="image" src="https://github.com/user-attachments/assets/73fc561f-48b7-43ed-a3c1-8002648abb50" />

SW (Software) — 애플리케이션 및 운영체제 계층

MicroBlaze (Firmware / Middleware) — 드라이버 및 GPIO 제어 계층

HW (Hardware) — 실제 하드웨어 회로층

즉, Application → OS → Driver → GPIO → HW 로 이어지는 계층적 구조로, 상위 계층이 하위 계층의 기능을 이용하는 형태입니다.

💻 SW (Software) 영역

Application (응용 프로그램)

사용자가 작성하는 프로그램입니다.

예: LED를 켜거나, 센서 데이터를 읽어 화면에 표시하는 코드.

하위 OS나 드라이버 함수를 호출하여 하드웨어 동작을 제어합니다.

OS (운영체제)

MicroBlaze 위에서 동작하는 임베디드 운영체제 (예: FreeRTOS, μC/OS-II 등)

스케줄링, 태스크 관리, 메모리 관리, 인터럽트 처리 등의 기능을 제공합니다.

Application과 하드웨어 간의 추상화 계층(Abstraction Layer) 역할을 합니다.

⚙️ MicroBlaze 계층

Driver (드라이버)

OS와 하드웨어(GPIO) 사이를 연결하는 인터페이스입니다.

예: GPIO 드라이버, UART 드라이버, SPI 드라이버 등

하드웨어 제어를 위한 레지스터 접근, 인터럽트 처리 등을 수행합니다.

GPIO (General Purpose Input/Output)

MicroBlaze가 외부 하드웨어와 직접 신호를 주고받는 모듈입니다.

예: 버튼 입력, LED 출력, 센서 트리거 제어 등

실제 물리적 핀과 연결되어 있습니다.

🔩 HW (Hardware) 영역

HW (하드웨어 회로 블록)

FPGA 내부에서 구현된 실제 논리 회로 또는 외부 디바이스입니다.

예: LED 회로, 센서, 통신 모듈, 메모리 인터페이스 등

GPIO나 IP 코어를 통해 MicroBlaze와 직접 연결됩니다.


<img width="653" height="388" alt="image" src="https://github.com/user-attachments/assets/1ea89abf-0cd5-4915-81a4-cd7314292c1b" 


  AXI Interface (레지스터 접근 인터페이스)
→ CPU(MicroBlaze 등)가 AXI 버스를 통해 타이머 제어 및 상태를 읽거나 쓰는 영역

Custom IP Logic (Timer 동작 로직)
→ 실제로 카운터를 동작시키고, 지정된 조건에서 tick 신호를 발생시키는 하드웨어 블록

⚙️ AXI Interface 영역

AXI 인터페이스는 프로세서(예: MicroBlaze)와 타이머 IP 간 통신을 위한 레지스터 맵입니다.
다음과 같은 주요 제어 레지스터들이 있습니다:

레지스터명	기능 설명
TMR_CR (Timer Control Register)	타이머의 동작 제어 신호 (Enable, Reset, Interrupt Enable 등)
PSC_TOP (Prescaler Top Value)	분주기(PSC)의 최댓값 — 입력 클록을 느리게 나누기 위해 사용
CNT_TOP (Counter Top Value)	카운터(CNT)가 도달해야 할 최댓값 — 이 값을 기준으로 tick 발생
CNT (Current Counter Value)	현재 카운터 값 (읽기 전용 혹은 테스트용 쓰기 가능)

AXI 인터페이스를 통해 CPU가 위 레지스터를 설정하면, Custom IP 내부 타이머의 동작이 결정됩니다.

🔧 Custom IP 내부 동작

Custom IP 부분은 실제 타이머의 동작을 수행합니다. 내부에는 보통 분주기(PSC, Prescaler) 와 카운터(CNT) 가 존재합니다.

PSC (Prescaler)

입력 클록을 나누어 타이머 동작 속도를 조절합니다.

예: 입력 클록이 100MHz일 때 PSC_TOP = 99 → 1MHz로 감소 (100분의 1 속도)

PSC가 PSC_TOP에 도달하면 CNT를 1 증가시키고 0으로 리셋합니다.

CNT (Counter)

PSC에서 넘어온 tick마다 1씩 증가하는 카운터입니다.

CNT가 CNT_TOP에 도달하면 tick 신호를 발생시킵니다.

tick은 외부 출력(예: 인터럽트, PWM, 트리거 신호 등)으로 연결될 수 있습니다.

논리 연산(AND 게이트 부분)

TMR_CR의 enable 신호와 내부 동작 상태를 조합하여 타이머가 동작할지 결정합니다.

예: Enable=1 & Reset=0 조건일 때만 카운터 동작.
