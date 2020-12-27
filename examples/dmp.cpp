
//#define SerialDebugging
#include "dmp.h"
#ifdef MPU6050_SENSOR

#endif
#ifdef L3GD20

#endif
#ifdef MPU9250_SENSOR
void MPU9250DMP::readGyro()
{
	long newTime = micros();
	float dt = ((float)(newTime - lastRead)) / 1000000.0;
	lastRead = newTime;
	mpu.readSensor();
	rot.x += dt * mpu.getGyroX_rads();
	rot.y += dt * mpu.getGyroY_rads();
	rot.z += dt * mpu.getGyroZ_rads();
}

void MPU9250DMP::readAccel()
{
	accel.x = mpu.getAccelX_mss();
	accel.y = mpu.getAccelY_mss();
	accel.z = mpu.getAccelZ_mss();
}
void MPU9250DMP::begin()
{
	mpu.begin();
	lastRead = micros();
}
#endif