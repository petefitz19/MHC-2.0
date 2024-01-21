#line 1 "/Users/pjfitz7e/Documents/Arduino/MHC_2_0_0/MidiDisplayManager.cpp"
#include "MidiDisplayManager.hpp"

using namespace MHC;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

MidiDisplayManager::MidiDisplayManager()
{
}

void MidiDisplayManager::Init()
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        for(;;); // Don't proceed, loop forever
    }

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setRotation(2);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("CH");

    display.setCursor(48, 0);
    display.println("B1");

    display.setCursor(92, 0);
    display.println("B2");

    display.display();
}

void MidiDisplayManager::Update(uint8_t inData1, uint8_t inData2, uint8_t inChannel)
{
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("CH");
    display.setCursor(0, 18);
    display.print(inChannel);

    display.setCursor(48, 0);
    display.println("B1");
    display.setCursor(48, 18);
    display.println(inData1);

    display.setCursor(92, 0);
    display.println("B2");
    display.setCursor(92, 18);
    display.println(inData2);

    display.display();
}

void MidiDisplayManager::UpdateBank(uint8_t bank)
{
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Bank:");
    display.setCursor(0, 18);

    if(bank != 0) {
        display.print(bank);
    }
    else {
        display.print("PROG");
    }

    display.display();
}
