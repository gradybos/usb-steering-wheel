# USB Steering Wheel
Retroactive senior capstone Github repository.

## Problem Statement
Racing simulators are used by hobbyists and professionals alike, but for someone new to the sport, there are very few budget-friendly, competitive hardware options. This project aimed to create a budget-friendly USB steering wheel by cutting luxury materials while maintaining competitive viability through careful component selection.

## Demo

![Final System](./images/system.png)

This image shows the physical wheel, along with its buttons. The button layout is modeled after other game controllers, and is useful for navigating menus or performing in-game actions.

## Components

![Encoder](./images/encoder.png)

The [AS5600 encoder](https://www.walmart.com/ip/AS5600-Magnetic-Encoder-Magnetic-Induction-Angle-Measurement-Sensor-Module-12bit-High-Precision-with-Magnet-1set/17412909036?wmlspartner=wlpa&selectedSellerId=102895224&selectedOfferId=1608B281CFEA353BA20AE6E146EE366B&conditionGroupCode=1&wmlspartner=wlpa&cn=FY25-ENTP-PMAX_cnv_dps_dsn_dis_ad_entp_e_n&gclsrc=aw.ds&adid=222222222971608B281CFEA353BA20AE6E146EE366B_6736816237_21407473164&wl0=&wl1=g&wl2=c&wl3=&wl4=&wl5=9005779&wl6=&wl7=&wl8=&wl9=pla&wl10=5622660921&wl11=online&wl12=1608B281CFEA353BA20AE6E146EE366B&veh=sem&gad_source=4&gad_campaignid=21690411341&gbraid=0AAAAADmfBIo-iz8zbVffQWbq5N2Qbk0VN&gclid=Cj0KCQiA5NXXBhDEARIsABAJhdL9PlJJ-Of3f3Q8vfnFPJO5o-V9qmlSwr3zTatpCiHNQi1trwiHZMoaAlb3EALw_wcB) used, pictured above, was selected for a few main reasons. It offers 12-bit precision, analog or $I^{2}C$ communication, works with a 3.3V input, and comes at an incredibly cheap price. Alternative options proved to be more expensive and more complicated to set up and use.

The buttons used varied in size and color, but otherwise were just standard buttons. They are readily available on Digikey or any other electronics retailer for a cheap price.

The linear potentiometers used for the project were selected based on size and cost. Size is important since they are being used for the pedals, and thus must fit within the pedal's range of motion. Specifically, 6cm linear potentiometers at the lowest cost proved to be the optimal choice.

## Implementation

![Top Level](./images/topLevel.png)

![Potentiometer Graph](./images/potentiometers.png)

The above graph shows the results of testing the electrical characteristics of the linear potentiometers used in the pedals. 

![Encoder Graph](./images/encoderGraph.png)

## Results

![Results](./images/results.png)

## Future Work

There is quite a bit that could be improved in the next iteration of this project. Most importantly, the device should run from a PCB to eliminate the need for wires spanning across the device, as seen in the demo picture. This change alone would clean up the final project aesthetically, make it easier to use, and make it more durable.

Additionally, the base that holds up the wheel needs to either be heavier or attach to the desk. A problem that emerged during testing was that the wheel would not remain stationary if the user attempted a sudden movement. To solve this, making the wheel heavier could help to keep it in place on the desk. However the more consistent solution would be adding a clip or clamp that securely attaches the wheel to the desk.

Finally, it would be beneficial to test more materials to fabricate the final build from. Wood worked because it was cheap and durable, but it certainly feels odd to use a wooden wheel. Using plastic for the structure of the device along with rubber grips would go a long way in creating a more ergonomic and aesthetic device. If this solution were to be brought to market, it is also likely that mass production would be easier when using plastic compared to wood.
