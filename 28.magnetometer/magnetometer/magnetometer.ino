#include <Wire.h>
//#include <HMC5883L.h>
// 
//HMC5883L compass;

#define HMC5883L_ADDRESS              (0x0D)
#define HMC5883L_REG_CONFIG_A         (0x00)
#define HMC5883L_REG_CONFIG_B         (0x01)
#define HMC5883L_REG_MODE             (0x02)
#define HMC5883L_REG_OUT_X_M          (0x03)
#define HMC5883L_REG_OUT_X_L          (0x04)
#define HMC5883L_REG_OUT_Z_M          (0x05)
#define HMC5883L_REG_OUT_Z_L          (0x06)
#define HMC5883L_REG_OUT_Y_M          (0x07)
#define HMC5883L_REG_OUT_Y_L          (0x08)
#define HMC5883L_REG_STATUS           (0x09)
#define HMC5883L_REG_IDENT_A          (0x0A)
#define HMC5883L_REG_IDENT_B          (0x0B)
#define HMC5883L_REG_IDENT_C          (0x0C)

typedef enum
{
    HMC5883L_SAMPLES_8     = 0b11,
    HMC5883L_SAMPLES_4     = 0b10,
    HMC5883L_SAMPLES_2     = 0b01,
    HMC5883L_SAMPLES_1     = 0b00
} hmc5883l_samples_t;

typedef enum
{
    HMC5883L_DATARATE_75HZ       = 0b110,
    HMC5883L_DATARATE_30HZ       = 0b101,
    HMC5883L_DATARATE_15HZ       = 0b100,
    HMC5883L_DATARATE_7_5HZ      = 0b011,
    HMC5883L_DATARATE_3HZ        = 0b010,
    HMC5883L_DATARATE_1_5HZ      = 0b001,
    HMC5883L_DATARATE_0_75_HZ    = 0b000
} hmc5883l_dataRate_t;

typedef enum
{
    HMC5883L_RANGE_8_1GA     = 0b111,
    HMC5883L_RANGE_5_6GA     = 0b110,
    HMC5883L_RANGE_4_7GA     = 0b101,
    HMC5883L_RANGE_4GA       = 0b100,
    HMC5883L_RANGE_2_5GA     = 0b011,
    HMC5883L_RANGE_1_9GA     = 0b010,
    HMC5883L_RANGE_1_3GA     = 0b001,
    HMC5883L_RANGE_0_88GA    = 0b000
} hmc5883l_range_t;

typedef enum
{
    HMC5883L_IDLE          = 0b10,
    HMC5883L_SINGLE        = 0b01,
    HMC5883L_CONTINOUS     = 0b00
} hmc5883l_mode_t;

#ifndef VECTOR_STRUCT_H
#define VECTOR_STRUCT_H
struct Vector
{
    float XAxis;
    float YAxis;
    float ZAxis;
};
#endif

class HMC5883L
{
    public:

  bool begin(void);

  Vector readRaw(void);
  Vector readNormalize(void);

  void  setOffset(int xo, int yo);

  void  setRange(hmc5883l_range_t range);
  hmc5883l_range_t getRange(void);

  void  setMeasurementMode(hmc5883l_mode_t mode);
  hmc5883l_mode_t getMeasurementMode(void);

  void  setDataRate(hmc5883l_dataRate_t dataRate);
  hmc5883l_dataRate_t getDataRate(void);

  void  setSamples(hmc5883l_samples_t samples);
  hmc5883l_samples_t getSamples(void);

    private:

  float mgPerDigit;
  Vector v;
  int xOffset, yOffset;

  void writeRegister8(uint8_t reg, uint8_t value);
  uint8_t readRegister8(uint8_t reg);
  uint8_t fastRegister8(uint8_t reg);
  int16_t readRegister16(uint8_t reg);
};
bool HMC5883L::begin()
{
    Wire.begin();

    if ((fastRegister8(HMC5883L_REG_IDENT_A) != 0x48)
    || (fastRegister8(HMC5883L_REG_IDENT_B) != 0x34)
    || (fastRegister8(HMC5883L_REG_IDENT_C) != 0x33))
    {
      Serial.println(fastRegister8(HMC5883L_REG_IDENT_A));
      Serial.println(fastRegister8(HMC5883L_REG_IDENT_B));
      Serial.println(fastRegister8(HMC5883L_REG_IDENT_C));
  return false;
    }
Serial.println("Hello!!");
    setRange(HMC5883L_RANGE_1_3GA);
    setMeasurementMode(HMC5883L_CONTINOUS);
    setDataRate(HMC5883L_DATARATE_15HZ);
    setSamples(HMC5883L_SAMPLES_1);

    mgPerDigit = 0.92f;

    return true;
}

Vector HMC5883L::readRaw(void)
{
    v.XAxis = readRegister16(HMC5883L_REG_OUT_X_M) - xOffset;
    v.YAxis = readRegister16(HMC5883L_REG_OUT_Y_M) - yOffset;
    v.ZAxis = readRegister16(HMC5883L_REG_OUT_Z_M);

    return v;
}

Vector HMC5883L::readNormalize(void)
{
    v.XAxis = ((float)readRegister16(HMC5883L_REG_OUT_X_M) - xOffset) * mgPerDigit;
    v.YAxis = ((float)readRegister16(HMC5883L_REG_OUT_Y_M) - yOffset) * mgPerDigit;
    v.ZAxis = (float)readRegister16(HMC5883L_REG_OUT_Z_M) * mgPerDigit;

    return v;
}

void HMC5883L::setOffset(int xo, int yo)
{
    xOffset = xo;
    yOffset = yo;
}

void HMC5883L::setRange(hmc5883l_range_t range)
{
    switch(range)
    {
  case HMC5883L_RANGE_0_88GA:
      mgPerDigit = 0.073f;
      break;

  case HMC5883L_RANGE_1_3GA:
      mgPerDigit = 0.92f;
      break;

  case HMC5883L_RANGE_1_9GA:
      mgPerDigit = 1.22f;
      break;

  case HMC5883L_RANGE_2_5GA:
      mgPerDigit = 1.52f;
      break;

  case HMC5883L_RANGE_4GA:
      mgPerDigit = 2.27f;
      break;

  case HMC5883L_RANGE_4_7GA:
      mgPerDigit = 2.56f;
      break;

  case HMC5883L_RANGE_5_6GA:
      mgPerDigit = 3.03f;
      break;

  case HMC5883L_RANGE_8_1GA:
      mgPerDigit = 4.35f;
      break;

  default:
      break;
    }

    writeRegister8(HMC5883L_REG_CONFIG_B, range << 5);
}

hmc5883l_range_t HMC5883L::getRange(void)
{
    return (hmc5883l_range_t)((readRegister8(HMC5883L_REG_CONFIG_B) >> 5));
}

void HMC5883L::setMeasurementMode(hmc5883l_mode_t mode)
{
    uint8_t value;

    value = readRegister8(HMC5883L_REG_MODE);
    value &= 0b11111100;
    value |= mode;

    writeRegister8(HMC5883L_REG_MODE, value);
}

hmc5883l_mode_t HMC5883L::getMeasurementMode(void)
{
    uint8_t value;

    value = readRegister8(HMC5883L_REG_MODE);
    value &= 0b00000011;

    return (hmc5883l_mode_t)value;
}

void HMC5883L::setDataRate(hmc5883l_dataRate_t dataRate)
{
    uint8_t value;

    value = readRegister8(HMC5883L_REG_CONFIG_A);
    value &= 0b11100011;
    value |= (dataRate << 2);

    writeRegister8(HMC5883L_REG_CONFIG_A, value);
}

hmc5883l_dataRate_t HMC5883L::getDataRate(void)
{
    uint8_t value;

    value = readRegister8(HMC5883L_REG_CONFIG_A);
    value &= 0b00011100;
    value >>= 2;

    return (hmc5883l_dataRate_t)value;
}

void HMC5883L::setSamples(hmc5883l_samples_t samples)
{
    uint8_t value;

    value = readRegister8(HMC5883L_REG_CONFIG_A);
    value &= 0b10011111;
    value |= (samples << 5);

    writeRegister8(HMC5883L_REG_CONFIG_A, value);
}

hmc5883l_samples_t HMC5883L::getSamples(void)
{
    uint8_t value;

    value = readRegister8(HMC5883L_REG_CONFIG_A);
    value &= 0b01100000;
    value >>= 5;

    return (hmc5883l_samples_t)value;
}

// Write byte to register
void HMC5883L::writeRegister8(uint8_t reg, uint8_t value)
{
    Wire.beginTransmission(HMC5883L_ADDRESS);
    #if ARDUINO >= 100
        Wire.write(reg);
        Wire.write(value);
    #else
        Wire.send(reg);
        Wire.send(value);
    #endif
    Wire.endTransmission();
}

// Read byte to register
uint8_t HMC5883L::fastRegister8(uint8_t reg)
{
    uint8_t value;
    Wire.beginTransmission(HMC5883L_ADDRESS);
    #if ARDUINO >= 100
        Wire.write(reg);
    #else
        Wire.send(reg);
    #endif
    Wire.endTransmission();

    Wire.requestFrom(HMC5883L_ADDRESS, 1);
    #if ARDUINO >= 100
        value = Wire.read();
    #else
        value = Wire.receive();
    #endif;
    Wire.endTransmission();
    return value;
}

// Read byte from register
uint8_t HMC5883L::readRegister8(uint8_t reg)
{
    uint8_t value;
    Wire.beginTransmission(HMC5883L_ADDRESS);
    #if ARDUINO >= 100
        Wire.write(reg);
    #else
        Wire.send(reg);
    #endif
    Wire.endTransmission();

    Wire.beginTransmission(HMC5883L_ADDRESS);
    Wire.requestFrom(HMC5883L_ADDRESS, 1);
    while(!Wire.available()) {};
    #if ARDUINO >= 100
        value = Wire.read();
    #else
        value = Wire.receive();
    #endif;
    Wire.endTransmission();

    return value;
}

// Read word from register
int16_t HMC5883L::readRegister16(uint8_t reg)
{
    int16_t value;
    Wire.beginTransmission(HMC5883L_ADDRESS);
    #if ARDUINO >= 100
        Wire.write(reg);
    #else
        Wire.send(reg);
    #endif
    Wire.endTransmission();

    Wire.beginTransmission(HMC5883L_ADDRESS);
    Wire.requestFrom(HMC5883L_ADDRESS, 2);
    while(!Wire.available()) {};
    #if ARDUINO >= 100
        uint8_t vha = Wire.read();
        uint8_t vla = Wire.read();
    #else
        uint8_t vha = Wire.receive();
        uint8_t vla = Wire.receive();
    #endif;
    Wire.endTransmission();

    value = vha << 8 | vla;

    return value;
}

HMC5883L compass;

void setup()
{
  Serial.begin(115200);
 
  // Inicjalizacja HMC5883L
  Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println("no response");
    delay(500);
  }
 
  // Ustawienie zakresu pomiarowego
  // +/- 0.88 Ga: HMC5883L_RANGE_0_88GA
  // +/- 1.30 Ga: HMC5883L_RANGE_1_3GA (domyslny)
  // +/- 1.90 Ga: HMC5883L_RANGE_1_9GA
  // +/- 2.50 Ga: HMC5883L_RANGE_2_5GA
  // +/- 4.00 Ga: HMC5883L_RANGE_4GA
  // +/- 4.70 Ga: HMC5883L_RANGE_4_7GA
  // +/- 5.60 Ga: HMC5883L_RANGE_5_6GA
  // +/- 8.10 Ga: HMC5883L_RANGE_8_1GA
  compass.setRange(HMC5883L_RANGE_1_3GA);
 
  // Ustawienie trybu pracy
  // Uspienie:              HMC5883L_IDLE
  // Pojedynczy pomiar:     HMC5883L_SINGLE
  // Ciagly pomiar: HMC5883L_CONTINOUS (domyslny)
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
 
  // Ustawienie czestotliwosci pomiarow
  //  0.75Hz: HMC5883L_DATARATE_0_75HZ
  //  1.50Hz: HMC5883L_DATARATE_1_5HZ
  //  3.00Hz: HMC5883L_DATARATE_3HZ
  //  7.50Hz: HMC5883L_DATARATE_7_50HZ
  // 15.00Hz: HMC5883L_DATARATE_15HZ (domyslny)
  // 30.00Hz: HMC5883L_DATARATE_30HZ
  // 75.00Hz: HMC5883L_DATARATE_75HZ
  compass.setDataRate(HMC5883L_DATARATE_15HZ);
 
  // Liczba usrednionych probek
  // 1 probka:  HMC5883L_SAMPLES_1 (domyslny)
  // 2 probki: HMC5883L_SAMPLES_2
  // 4 probki: HMC5883L_SAMPLES_4
  // 8 probki: HMC5883L_SAMPLES_8
  compass.setSamples(HMC5883L_SAMPLES_1);
}
 
void loop()
{
  // Pobranie pomiarow surowych
  Vector raw = compass.readRaw();
 
  // Pobranie pomiarow znormalizowanych
  Vector norm = compass.readNormalize();
 
  // Wyswielnie wynikow
  Serial.print(" Xraw = ");
  Serial.print(raw.XAxis);
  Serial.print(" Yraw = ");
  Serial.print(raw.YAxis);
  Serial.print(" Zraw = ");
  Serial.print(raw.ZAxis);
  Serial.print(" Xnorm = ");
  Serial.print(norm.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(norm.YAxis);
  Serial.print(" ZNorm = ");
  Serial.print(norm.ZAxis);
  Serial.println();  
 
  delay(100);
}
