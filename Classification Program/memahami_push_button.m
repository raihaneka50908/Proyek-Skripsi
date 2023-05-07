function memahami_push_button()

myPi=raspi('169.254.29.168','pi','raspberry');
LED_PIN=21;
PUSH_BUTTON=20;

configurePin(myPi,LED_PIN,'DigitalOutput');
configurePin(myPi,PUSH_BUTTON,'DigitalInput');

while true
    if readDigitalPin(myPi,PUSH_BUTTON)==1
        writeDigitalPin(myPi,LED_PIN,1);
    else
        writeDigitalPin(myPi,LED_PIN,0)
    end
end

end