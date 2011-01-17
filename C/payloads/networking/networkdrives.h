#ifndef PD_NETWORK_DRIVES_H
#define PD_NETWORK_DRIVES_H

#define MAPPING_NOTPERSISTENT 0x00
#define MAPPING_PERSISTENT 0x01

void MapNetworkDrive(const char* driveLetter, const char* UNCpath, uint8_t persistent);
void MapNetworkDriveWithCredentials(const char* driveLetter, const char* UNCpath, uint8_t persistent, const char* username, const char* password);
void RemoveDriveMapping(const char* driveLetter);

#endif /* PD_NETWORK_DRIVES_H */