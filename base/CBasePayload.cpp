#include "CBasePayload.h"

bool CBasePayload::IsEnabled() {
	return m_bEnabled;
}
void CBasePayload::Disable() {
	m_bEnabled = false;
}
void CBasePayload::Enable() {
	m_bEnabled = true;
}
void CBasePayload::Run() {
	Initialise();
	while (IsEnabled() && MainLoop() );
}

