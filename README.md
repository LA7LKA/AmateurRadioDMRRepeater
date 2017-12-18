# AmateurRadioDMRRepeater

This is an attempt at making a 70cm DMR repeater which supports VoCoders AMBE+2 and Codec2. It will also support connecting to the Brandmeister DMR network.

The first version is an experiment model with Silicon lab Si4463 for RX and TX.
The modules with Si4463 is connected to a Raspberry Pi 3.

<h2>Progress</h2></p>

9. December 2017: </h3> </p>
Started writing some more code just for using one module to test the code a bit.</p>
Did hookup one module to Raspberry Pi 3:</p>
![Alt text](IMG_20171209_135748.jpg?raw=true "module hookup")

<p><h3>18. December 2017: </h3> </p>

Managed to get SPI communication up and running with one Si4463 RF IC.</p>
 <table style="width:100%">
 <caption>Hookup with one radio module to Raspberry Pi 3</caption>
  <tr>
    <th>Raspberry Pi 3 Pin</th>
    <th>Si4463 module/th>
  </tr>
  <tr>
    <td>6, GND</td>
    <td>18, GPIO24</td>
    <td>16, GPIO23</td>
    <td>19, MOSI</td>
    <td>21, MISO</td>
    <td>23, SCK</td>
    <td>13, GPIO27</td>
    <td>1, +3,3VDC</td>

  </tr>
  <tr>
    <td>1, GND</td>
    <td>2, SDN</td>
    <td>5, nSEL</td>
    <td>6, MOSI</td>
    <td>7, MISO</td>
    <td>8, SCK</td>
    <td>9, IRQ</td>
    <td>12, VCC => +3,3VDC</td>
  </tr>

</table> 


73&88 de LA7LKA
