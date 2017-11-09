##############
## Script listens to serial port and writes contents into a file
##############
## requires pySerial to be installed
import serial

serial_port = '/dev/tty.wchusbserial1420';
baud_rate = 57600; #In arduino, Serial.begin(baud_rate)
write_to_file_path = "output.txt";

output_file = open(write_to_file_path, "w+");
ser = serial.Serial(serial_port, baud_rate)

value = 0;

while value < 150:
    line = ser.readline();
    line = line.decode("ascii") #ser.readline returns a binary, convert to string
    print(value);
    print(line);
    output_file.write(line);
    value = value + 1;



output_file.close();
