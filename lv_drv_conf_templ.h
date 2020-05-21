/*
 * @file lv_drv_conf.h
 *
 */

/*
 * COPY THIS FILE AS lv_drv_conf.h
 */

#if 0 /*Set it to "1" to enable the content*/

#ifndef LV_DRV_CONF_H
#define LV_DRV_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lv_conf.h"

/*********************
 *      INCLUDES
 *********************/
/* Add specific sdk include here */

/*********************
 *       DEFINES
 *********************/
/* Disable with 0 if driver don't use an specific api */
#define LV_DRIVER_ENABLE_COMMON 1
#define LV_DRIVER_ENABLE_DELAY 1
#define LV_DRIVER_ENABLE_I2C 1
#define LV_DRIVER_ENABLE_SPI 1
#define LV_DRIVER_ENABLE_PAR 1

/* use this macro if you want ignore a gpio write/read. e.g: spi.cs = LV_DRIVER_NOPIN */
#define LV_DRIVER_NOPIN (0xFFFF)

/* use this macro to add specific attribute to function call into an interupt routines */
#define INTERUPT_ATTRIBUTE
/**********************
 *      TYPEDEFS
 **********************/
/* You can use a pointer handler or just a id number to reder to a device
 * e.g: typedef const uint8_t lv_gpio_handle_t if you need just a bus id
 * You can use device descriptor from your sdk too.
 */
typedef const void* lv_gpio_handle_t;
typedef const void* lv_i2c_handle_t;
typedef const void* lv_spi_handle_t;
typedef const void* lv_par_handle_t;
typedef const void* lv_uart_handle_t;

/*********************
 * 	HAL INTERFACE
 *********************/
/*
 * All used peripherals must be initialized in user application, library only
 * manipulate them.
 * You can use a device descriptor from your SDK or  do your own in this file too.
 * example:
 * typedef struct lv_spi_dev_t { .... };
 */

/*------------
 *  Delay
 *------------*/
#if LV_DRIVER_ENABLE_DELAY

/**
 * Delay the given number of microseconds
 * @param us Time to wait in us
 */
static inline void lv_delay_us(const uint32_t us)
{
    //Do the dependant port here
}

/**
 * Delay the given number of milliseconds
 * @param ms Time to wait in ms
 */
static inline void lv_delay_ms(const uint32_t ms)
{
    //Do the dependant port here
}

/**
 * Return system time
 * @return system time (ms)
 */
static inline uint32_t lv_get_ms()
{
    //Do the dependant port here
}

#endif
/*------------
 *  Common
 *------------*/
#if LV_DRIVER_ENABLE_COMMON

/**
 * Change a pin level
 * @param pin gpio Number
 * @param val Level to set
 */
static inline void lv_gpio_write(lv_gpio_handle_t gpio, const uint8_t val)
{
    //Do the dependant port here
}

/**
 * Read current level gpio
 * @param pin gpio to read
 * @return gpio value
 */
static inline uint8_t lv_gpio_read(lv_gpio_handle_t gpio)
{
    //Do the dependant port here
}

#endif
/*---------
 *  I2C
 *---------*/
#if LV_DRIVER_ENABLE_I2C

/**
 * Do a I2C write transmission on 8 bits register device.
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
static inline int lv_i2c_write(lv_i2c_handle_t i2c_dev, const uint8_t* reg, const void* data_out, uint16_t datalen)
{
    //Do the dependant port here
}

/**
 * Do a I2C read transmission on 8 bits register device.
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
static inline int lv_i2c_read(lv_i2c_handle_t i2c_dev, const uint8_t* reg, void* data_in, uint16_t datalen)
{
    //Do the dependant port here
}

/**
 * Do a I2C write transmissionon 16 bits register device
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
static inline int lv_i2c_write16(lv_i2c_handle_t i2c_dev, const uint16_t* reg, const void* data_out, uint16_t datalen)
{
    //Do the dependant port here
}

/**
 * Do a I2C write transmissionon 16 bits register device.
 * @param i2c_dev Pointer to i2c device
 * @param reg Pointer to register address to send if non-null
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
static inline int lv_i2c_read16(lv_i2c_handle_t i2c_dev, const uint16_t* reg, void* data_in, uint16_t datalen)
{
    //Do the dependant port here
}

#endif
/*---------
 *  SPI
 *---------*/
#if LV_DRIVER_ENABLE_SPI

typedef enum {
  LV_SPI_COMMAND,
  LV_SPI_ADDRESS,
  LV_SPI_DUMMY,
} lv_spi_reg_t;

/**
 * Control SPI cs pin.
 * @param spi_dev Pointer to spi device
 * @param lvl Gpio Level
 */
static inline void lv_spi_wr_cs(lv_spi_handle_t spi_dev, uint8_t lvl)
{
    //Do the dependant port here
}

/**
 * Control SPI dc pin.
 * @param spi_dev Pointer to spi device
 * @param lvl Gpio Level
 */
static inline void lv_spi_wr_dc(lv_spi_handle_t spi_dev, uint8_t lvl)
{
    //Do the dependant port here
}

/**
 * Do a SPI transaction .
 * @param spi_dev Pointer to spi device
 * @param data_in Receive buffer. If NULL, received data will be lost.
 * @param data_out Data to send buffer. If NULL, it will only receive data.
 * @param len Buffer size in words
 * @param word_size Size of the word in byte
 * @return Non-Zero if error occured
 */
static inline int lv_spi_transaction(lv_spi_handle_t spi_dev, void* data_in, const void* data_out, uint16_t len, uint8_t word_size)
{
    //Do the dependant port here
}

/**
 * Do a SPI repeat send.
 * @param spi_dev Pointer to spi device
 * @param template Pointer toTemplate to send throw spi.
 * @param repeats Copy number
 * @param template_size Size of the template in byte
 * @return Non-Zero if error occured
 */
static inline int lv_spi_repeat(lv_spi_handle_t spi_dev, const void* template, uint32_t repeats, uint8_t template_size)
{
    //Do the dependant port here
}

/**
 * Set command to send for spi transaction
 * @param spi_dev Pointer to spi device
 * @param reg SPI register to set (dummy/command/address)
 * @param value Value
 * @param bits Bits number
 * @return Non-Zero if error occured
 */
static inline int lv_drv_spi_set_preemble(lv_spi_handle_t spi_dev, lv_spi_reg_t reg, uint32_t value, uint8_t bits)
{
    //Do the dependant port here
}

/**
 * Clear spi bus command
 * @param spi_dev Pointer to spi device
 * @param reg SPI register to clear (dummy/command/address)
 * @return Non-Zero if error occured
 */
static inline int lv_spi_clr_preemble(lv_spi_handle_t spi_dev, lv_spi_reg_t reg)
{
    //Do the dependant port here
}

#endif
/*------------------
 *  Parallel port
 *-----------------*/
#if LV_DRIVER_ENABLE_PAR
/**
 * Control Parallel cs pin.
 * @param par_dev Pointer to parallel device
 * @param lvl Gpio Level
 */
static inline void lv_par_wr_cs(lv_par_handle_t par_dev, uint8_t lvl)
{
    //Do the dependant port here
}

/**
 * Control Parallel dc pin.
 * @param par_dev Pointer to parallel device
 * @param lvl Gpio Level
 */
static inline void lv_par_wr_dc(lv_par_handle_t par_dev, uint8_t lvl)
{
    //Do the dependant port here
}

/**
 * Do a Parallel port write.
 * @param par_dev Pointer to parallel port device
 * @param data_out Pointer to data buffer to send
 * @param len Buffer size in words
 * @param word_size Size of the word in byte
 * @return Non-Zero if error occured
 */
static inline int lv_par_write(lv_par_handle_t par_dev, const void* data_out, uint16_t len, uint8_t word_size)
{
    //Do the dependant port here
}

/**
 * Do a Parallel port read.
 * @param par_dev Pointer to parallel port device
 * @param data_in Pointer to data buffer to read
 * @param len Buffer size in words
 * @param word_size Size of the word in byte
 * @return Non-Zero if error occured
 */
static inline int lv_par_read(lv_par_handle_t par_dev, void* data_in, uint16_t len, uint8_t word_size)
{
    //Do the dependant port here
}

/*---------
 *  UART
 *---------*/
/**
 * Do a uart write transmission.
 * @param uart_dev Pointer to uart device
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to send
 * @return Non-Zero if error occured
 */
static inline int lv_uart_write(lv_uart_handle_t uart_dev, const void* data_out, uint16_t datalen)
{
    //Do the dependant port here
}

/**
 * Do a uart read transmission
 * @param uart_dev Pointer to uart device
 * @param data_out Pointer to data buffer to send if non-null
 * @param datalen Number of data byte to read
 * @return Non-Zero if error occured
 */
static inline int lv_uart_read(lv_uart_handle_t uart_dev, void* data_in, uint16_t datalen)
{
    //Do the dependant port here
}

#endif
/*********************
 *  DISPLAY DRIVERS
 *********************/

/*-------------------
 *  Monitor of PC
 *-------------------*/
#ifndef USE_MONITOR
#  define USE_MONITOR         0
#endif

#if USE_MONITOR
#  define MONITOR_HOR_RES     LV_HOR_RES
#  define MONITOR_VER_RES     LV_VER_RES

/* Scale window by this factor (useful when simulating small screens) */
#  define MONITOR_ZOOM        1

/* Used to test true double buffering with only address changing.
 * Set LV_VDB_SIZE = (LV_HOR_RES * LV_VER_RES) and  LV_VDB_DOUBLE = 1 and LV_COLOR_DEPTH = 32" */
#  define MONITOR_DOUBLE_BUFFERED 0

/*Eclipse: <SDL2/SDL.h>    Visual Studio: <SDL.h>*/
#  define MONITOR_SDL_INCLUDE_PATH    <SDL2/SDL.h>

/*Open two windows to test multi display support*/
#  define MONITOR_DUAL            0
#endif

/*-----------------------------------
 *  Native Windows (including mouse)
 *----------------------------------*/
#ifndef USE_WINDOWS
#  define USE_WINDOWS       0
#endif

#define USE_WINDOWS         0
#if USE_WINDOWS
#  define WINDOW_HOR_RES      480
#  define WINDOW_VER_RES      320
#endif

/*----------------
 *    ILI9341
 *--------------*/
#define USE_ILI9341        1
#if USE_ILI9341
#define ILI9341_DEBUG              (0)
#define ILI9341_ERR_CHECK          (0)  //retrieve err from transaction if true
#define ILI9341_PAR_SUPPORT        (1)
#define ILI9341_SPI4WIRE_SUPPORT   (1)
#define ILI9341_SPI3WIRE_SUPPORT   (1)
#define ILI9341_EXTC_SUPPORT       (0)  //EXTC pin high ? Set at 1 if yes for extended command usage.
#define ILI9341_MAX_SAMPLE         (64) //Pixel sample size to send (N byte x Pixel Size)
#define ILI9341_SERIAL_BYTESWAP    (0)  //Set Endiannes Swap { 0: None, 1: CPU Swap, 2: ILI9341 swap(need EXTC) }
#endif

/*----------------
 *    SSD1963
 *--------------*/
#ifndef USE_SSD1963
#  define USE_SSD1963         0
#endif

#if USE_SSD1963
#  define SSD1963_HOR_RES     LV_HOR_RES
#  define SSD1963_VER_RES     LV_VER_RES
#  define SSD1963_HT          531
#  define SSD1963_HPS         43
#  define SSD1963_LPS         8
#  define SSD1963_HPW         10
#  define SSD1963_VT          288
#  define SSD1963_VPS         12
#  define SSD1963_FPS         4
#  define SSD1963_VPW         10
#  define SSD1963_HS_NEG      0   /*Negative hsync*/
#  define SSD1963_VS_NEG      0   /*Negative vsync*/
#  define SSD1963_ORI         0   /*0, 90, 180, 270*/
#  define SSD1963_COLOR_DEPTH 16
#endif

/*----------------
 *    SSD1306
 *--------------*/
#define USE_SSD1306        1
#if USE_SSD1306
#define SSD1306_DEBUG              (0)
#define SSD1306_HOR_RES            (LV_HOR_RES)
#define SSD1306_VER_RES            (LV_VER_RES)
#define SSD1306_ERR_CHECK          (0)
#define SSD1306_I2C_SUPPORT        (1)
#define SSD1306_SPI_4_WIRE_SUPPORT (1)
#define SSD1306_SPI_3_WIRE_SUPPORT (1)
#endif

/*----------------
 *    R61581
 *--------------*/
#ifndef USE_R61581
#  define USE_R61581          0
#endif

#if USE_R61581
#  define R61581_HOR_RES      LV_HOR_RES
#  define R61581_VER_RES      LV_VER_RES
#  define R61581_HSPL         0       /*HSYNC signal polarity*/
#  define R61581_HSL          10      /*HSYNC length (Not Implemented)*/
#  define R61581_HFP          10      /*Horitontal Front poarch (Not Implemented)*/
#  define R61581_HBP          10      /*Horitontal Back poarch (Not Implemented */
#  define R61581_VSPL         0       /*VSYNC signal polarity*/
#  define R61581_VSL          10      /*VSYNC length (Not Implemented)*/
#  define R61581_VFP          8       /*Vertical Front poarch*/
#  define R61581_VBP          8       /*Vertical Back poarch */
#  define R61581_DPL          0       /*DCLK signal polarity*/
#  define R61581_EPL          1       /*ENABLE signal polarity*/
#  define R61581_ORI          0       /*0, 180*/
#  define R61581_LV_COLOR_DEPTH 16    /*Fix 16 bit*/
#endif

/*------------------------------
 *  ST7565 (Monochrome, low res.)
 *-----------------------------*/
#ifndef USE_ST7565
#  define USE_ST7565          0
#endif

#if USE_ST7565
/*No settings*/
#endif  /*USE_ST7565*/

/*------------------------------------------
 *  UC1610 (4 gray 160*[104|128])
 *  (EA DOGXL160 160x104 tested)
 *-----------------------------------------*/
#ifndef USE_UC1610
#  define USE_UC1610          0
#endif

#if USE_UC1610
#  define UC1610_HOR_RES         LV_HOR_RES
#  define UC1610_VER_RES         LV_VER_RES
#  define UC1610_INIT_CONTRAST   33   /* init contrast, values in [%] */
#  define UC1610_INIT_HARD_RST   0    /* 1 : hardware reset at init, 0 : software reset */
#  define UC1610_TOP_VIEW        0    /* 0 : Bottom View, 1 : Top View */
#endif  /*USE_UC1610*/

/*-------------------------------------------------
 *  SHARP memory in pixel monochrome display series
 *      LS012B7DD01 (184x38  pixels.)
 *      LS013B7DH03 (128x128 pixels.)
 *      LS013B7DH05 (144x168 pixels.)
 *      LS027B7DH01 (400x240 pixels.) (tested)
 *      LS032B7DD02 (336x536 pixels.)
 *      LS044Q7DH01 (320x240 pixels.)
 *------------------------------------------------*/
#ifndef USE_SHARP_MIP
#  define USE_SHARP_MIP       0
#endif

#if USE_SHARP_MIP
#  define SHARP_MIP_HOR_RES             LV_HOR_RES
#  define SHARP_MIP_VER_RES             LV_VER_RES
#  define SHARP_MIP_SOFT_COM_INVERSION  0
#  define SHARP_MIP_REV_BYTE(b)         /*((uint8_t) __REV(__RBIT(b)))*/  /*Architecture / compiler dependent byte bits order reverse*/
#endif  /*USE_SHARP_MIP*/

/*-----------------------------------------
 *  Linux frame buffer device (/dev/fbx)
 *-----------------------------------------*/
#ifndef USE_FBDEV
#  define USE_FBDEV           0
#endif

#if USE_FBDEV
#  define FBDEV_PATH          "/dev/fb0"
#endif

/*-----------------------------------------
 *  FreeBSD frame buffer device (/dev/fbx)
 *.........................................*/
#ifndef USE_BSD_FBDEV
#  define USE_BSD_FBDEV		0
#endif

#if USE_BSD_FBDEV
# define FBDEV_PATH		"/dev/fb0"
#endif

/*********************
 *  INPUT DEVICES
 *********************/

/*--------------
 *    AR1000
 *--------------*/
#define USE_AR10XX (1)
#if (USE_AR10XX != 0)
#define AR10XX_SPI_SUPPORT (1)
#define AR10XX_I2C_SUPPORT (1)
#define AR10XX_UART_SUPPORT (1)
#define AR10XX_DEBUG (0)
#define AR10XX_ERR_CHECK (0)
#define AR10XX_VERIFY_ANSWER (1)
#define AR10XX_COMPONENT (21) // Version of XX (10, 11, 20 , 21)
#endif

/*--------------
 *    XPT2046
 *--------------*/
#ifndef USE_XPT2046
#  define USE_XPT2046         0
#endif

#if USE_XPT2046
#  define XPT2046_HOR_RES     480
#  define XPT2046_VER_RES     320
#  define XPT2046_X_MIN       200
#  define XPT2046_Y_MIN       200
#  define XPT2046_X_MAX       3800
#  define XPT2046_Y_MAX       3800
#  define XPT2046_AVG         4
#  define XPT2046_X_INV       0
#  define XPT2046_Y_INV       0
#  define XPT2046_XY_SWAP     0
#endif

/*-----------------
 *    FT5406EE8
 *-----------------*/
#ifndef USE_FT5406EE8
#  define USE_FT5406EE8       0
#endif

#if USE_FT5406EE8
# define FT5406EE8_I2C_ADR   0x38                  /*7 bit address*/
#endif

/*---------------
 *  AD TOUCH
 *--------------*/
#ifndef USE_AD_TOUCH
#  define USE_AD_TOUCH        0
#endif

#if USE_AD_TOUCH
/*No settings*/
#endif


/*---------------------------------------
 * Mouse or touchpad on PC (using SDL)
 *-------------------------------------*/
#ifndef USE_MOUSE
#  define USE_MOUSE           0
#endif

#if USE_MOUSE
/*No settings*/
#endif

/*-------------------------------------------
 * Mousewheel as encoder on PC (using SDL)
 *------------------------------------------*/
#ifndef USE_MOUSEWHEEL
#  define USE_MOUSEWHEEL      0
#endif

#if USE_MOUSEWHEEL
/*No settings*/
#endif

/*-------------------------------------------------
 * Touchscreen as libinput interface (for Linux based systems)
 *------------------------------------------------*/
#ifndef USE_LIBINPUT
#  define USE_LIBINPUT           0
#endif

#if USE_LIBINPUT
#  define LIBINPUT_NAME   "/dev/input/event0"        /*You can use the "evtest" Linux tool to get the list of devices and test them*/
#endif  /*USE_LIBINPUT*/

/*-------------------------------------------------
 * Mouse or touchpad as evdev interface (for Linux based systems)
 *------------------------------------------------*/
#ifndef USE_EVDEV
#  define USE_EVDEV           0
#endif

#if USE_EVDEV
#  define EVDEV_NAME   "/dev/input/event0"        /*You can use the "evtest" Linux tool to get the list of devices and test them*/
#  define EVDEV_SWAP_AXES         0               /*Swap the x and y axes of the touchscreen*/

#  define EVDEV_SCALE             0               /* Scale input, e.g. if touchscreen resolution does not match display resolution */
#  if EVDEV_SCALE
#    define EVDEV_SCALE_HOR_RES     (4096)          /* Horizontal resolution of touchscreen */
#    define EVDEV_SCALE_VER_RES     (4096)          /* Vertical resolution of touchscreen */
#  endif  /*EVDEV_SCALE*/

#  define EVDEV_CALIBRATE         0               /*Scale and offset the touchscreen coordinates by using maximum and minimum values for each axis*/
#  if EVDEV_CALIBRATE
#    define EVDEV_HOR_MIN   3800                    /*If EVDEV_XXX_MIN > EVDEV_XXX_MAX the XXX axis is automatically inverted*/
#    define EVDEV_HOR_MAX   200
#    define EVDEV_VER_MIN   200
#    define EVDEV_VER_MAX   3800
#  endif  /*EVDEV_SCALE*/
#endif  /*USE_EVDEV*/

/*-------------------------------
 *   Keyboard of a PC (using SDL)
 *------------------------------*/
#ifndef USE_KEYBOARD
#  define USE_KEYBOARD        0
#endif

#if USE_KEYBOARD
/*No settings*/
#endif

#ifdef __cplusplus
}
#endif

#endif  /*LV_DRV_CONF_H*/

#endif /*Remove this to enable the content*/
