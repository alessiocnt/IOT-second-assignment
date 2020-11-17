#ifndef __SONAR__
#define __SONAR__

// Class that models a Sonar
class Sonar {
public:
    Sonar(int trigPin, int echoPin, float temperature);
    float getDistance();
    void setTemperature(float temperature);
private:
    int trigPin;
    int echoPin;
    float temperature;
    float soundSpeed;
    void updateSoundSpeed(float temperature);
};

#endif
