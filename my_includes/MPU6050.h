
/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 文档网站：wiki.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 嘉立创社区问答：https://www.jlc-bbs.com/lckfb
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 */
#ifndef _MPU6050_H_
#define _MPU6050_H_

#include "ti_msp_dl_config.h"
#include "my_uwtick.h"


// 根据 ti_msp_dl_config.h 的定义，手动声明 SDA/SCL
#define OLED_SDA_PORT   GPIOA            // SDA 端口 (GPIOA)
#define OLED_SDA_PIN    DL_GPIO_PIN_2    // SDA 引脚 (PA2)
#define OLED_SDA_IOMUX  IOMUX_PINCM7     // SDA 复用配置

#define OLED_SCL_PORT   GPIOA            // SCL 端口 (GPIOA)
#define OLED_SCL_PIN    DL_GPIO_PIN_1    // SCL 引脚 (PA1)
#define OLED_SCL_IOMUX  IOMUX_PINCM2     // SCL 复用配置

// 调整宏定义，直接使用上述变量
#define SDA_OUT()   do { \
    DL_GPIO_initDigitalOutput(OLED_SDA_IOMUX); \
    DL_GPIO_setPins(OLED_SDA_PORT, OLED_SDA_PIN); \
    DL_GPIO_enableOutput(OLED_SDA_PORT, OLED_SDA_PIN); \
} while(0)

#define SDA_IN()    { DL_GPIO_initDigitalInput(OLED_SDA_IOMUX); }

#define SDA_GET()   ( (DL_GPIO_readPins(OLED_SDA_PORT, OLED_SDA_PIN) & OLED_SDA_PIN) ? 1 : 0 )

#define SDA(x)      ( (x) ? DL_GPIO_setPins(OLED_SDA_PORT, OLED_SDA_PIN) : DL_GPIO_clearPins(OLED_SDA_PORT, OLED_SDA_PIN) )

#define SCL(x)      ( (x) ? DL_GPIO_setPins(OLED_SCL_PORT, OLED_SCL_PIN) : DL_GPIO_clearPins(OLED_SCL_PORT, OLED_SCL_PIN) )


//MPU6050的AD0是IIC地址引脚，接地则IIC地址为0x68,接VCC则IIC地址为0x69


#define MPU6050_RA_SMPLRT_DIV       0x19        //陀螺仪采样率 地址
#define MPU6050_RA_CONFIG           0x1A        //设置数字低通滤波器 地址
#define MPU6050_RA_GYRO_CONFIG      0x1B        //陀螺仪配置寄存器
#define MPU6050_RA_ACCEL_CONFIG     0x1C        //加速度传感器配置寄存器
#define MPU_INT_EN_REG              0X38        //中断使能寄存器
#define MPU_USER_CTRL_REG           0X6A        //用户控制寄存器
#define MPU_FIFO_EN_REG             0X23        //FIFO使能寄存器
#define MPU_PWR_MGMT2_REG           0X6C        //电源管理寄存器2
#define MPU_GYRO_CFG_REG            0X1B        //陀螺仪配置寄存器
#define MPU_ACCEL_CFG_REG           0X1C        //加速度计配置寄存器
#define MPU_CFG_REG                 0X1A        //配置寄存器
#define MPU_SAMPLE_RATE_REG         0X19        //采样频率分频器
#define MPU_INTBP_CFG_REG           0X37        //中断/旁路设置寄存器

#define MPU6050_RA_PWR_MGMT_1       0x6B
#define MPU6050_RA_PWR_MGMT_2       0x6C

#define MPU6050_WHO_AM_I            0x75
#define MPU6050_SMPLRT_DIV          0            //8000Hz
#define MPU6050_DLPF_CFG            0
#define MPU6050_GYRO_OUT            0x43         //MPU6050陀螺仪数据寄存器地址
#define MPU6050_ACC_OUT             0x3B         //MPU6050加速度数据寄存器地址

#define MPU6050_RA_TEMP_OUT_H       0x41        //温度高位
#define MPU6050_RA_TEMP_OUT_L       0x42        //温度低位

#define MPU_ACCEL_XOUTH_REG         0X3B        //加速度值,X轴高8位寄存器
#define MPU_ACCEL_XOUTL_REG         0X3C        //加速度值,X轴低8位寄存器
#define MPU_ACCEL_YOUTH_REG         0X3D        //加速度值,Y轴高8位寄存器
#define MPU_ACCEL_YOUTL_REG         0X3E        //加速度值,Y轴低8位寄存器
#define MPU_ACCEL_ZOUTH_REG         0X3F        //加速度值,Z轴高8位寄存器
#define MPU_ACCEL_ZOUTL_REG         0X40        //加速度值,Z轴低8位寄存器

#define MPU_TEMP_OUTH_REG           0X41        //温度值高八位寄存器
#define MPU_TEMP_OUTL_REG           0X42        //温度值低8位寄存器

#define MPU_GYRO_XOUTH_REG          0X43        //陀螺仪值,X轴高8位寄存器
#define MPU_GYRO_XOUTL_REG          0X44        //陀螺仪值,X轴低8位寄存器
#define MPU_GYRO_YOUTH_REG          0X45        //陀螺仪值,Y轴高8位寄存器
#define MPU_GYRO_YOUTL_REG          0X46        //陀螺仪值,Y轴低8位寄存器
#define MPU_GYRO_ZOUTH_REG          0X47        //陀螺仪值,Z轴高8位寄存器
#define MPU_GYRO_ZOUTL_REG          0X48        //陀螺仪值,Z轴低8位寄存器


char MPU6050_WriteReg(uint8_t addr,uint8_t regaddr,uint8_t num,uint8_t *regdata);
char MPU6050_ReadData(uint8_t addr, uint8_t regaddr,uint8_t num,uint8_t* Read);

char MPU6050_Init(void);
void MPU6050ReadGyro(short *gyroData);
void MPU6050ReadAcc(short *accData);
float MPU6050_GetTemp(void);
uint8_t MPU6050ReadID(void);

#endif