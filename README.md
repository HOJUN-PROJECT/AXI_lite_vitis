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
