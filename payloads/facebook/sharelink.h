#ifndef PL_FB_SHARELINK_H
#define PL_FB_SHARELINK_H

#define FBShareLink_windows_P(s, t) FBShareLink_windows(PSTR(s), PSTR(t))
#define FBShareLink_mac_P(s, t) FBShareLink_mac(PSTR(s), PSTR(t))
#define FBShareLink_linux_P(s, t) FBShareLink_linux(PSTR(s), PSTR(t))

void FBShareLink_windows(const char* link, const  char* text);
void FBShareLink_mac(const char* link, const  char* text);
void FBShareLink_linux(const char* link, const  char* text);

#endif /* PL_FB_SHARELINK_H */