#include "CPsydukCore.h"
#include "CUSBKeyboard.h"
#include "IPayload.h"
#include "shareddefs.h"
#include <util/delay.h>
#include "usb_keyboard.h"
#include "../payloads/payloads.h"

CPsydukCore::CPsydukCore() {
	m_bIsInitialised = false;
}

CPsydukCore::~CPsydukCore() {

}

#define ever ;;

void CPsydukCore::Run() {
	if (!m_bIsInitialised)
		Initialise();
	
#if USE_DUCKY_FUNCTIONS
	DuckyStart(this);
	while (DuckyRunLoop(this));
#else
	PAYLOAD_CLASS payload;
	payload.Run();
#endif
}

void CPsydukCore::Initialise() {
	
	CPU_PRESCALE(CPU_125kHz);
	_delay_ms(1);           // allow slow power supply startup
	CPU_PRESCALE(CPU_16MHz); // set for 16 MHz clock
	
	usb_init();
	while (!usb_configured()) {	}
	
	Delay(2000);
	
	m_bIsInitialised = true;
}

void CPsydukCore::Shutdown() {

}

void Delay(uint16_t ms) {
	_delay_ms(ms);
}