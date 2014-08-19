require 'serialport'
require 'gmail'
 
#plug in your username and password here
gmail = Gmail.connect("0000marcell@gmail.com", "brat86brat86")
#count the number of unread messages
prev_unread = gmail.inbox.count(:unread)
#this *will* be different for you
#You need to find out what port your arduino is on
#and also what the corresponding file is on /dev
#You can do this by looking at the bottom right of the Arduino
#environment which tells you what the path.
port_file = '/dev/tty.usbmodemfa131'
 
#this must be same as the baud rate set on the Arduino
#with Serial.begin
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE
#create a SerialPort object using each of the bits of information
port = SerialPort.new(port_file, baud_rate, data_bits, stop_bits, parity)
wait_time = 4
#for an infinite amount of time
loop do
  #get the number of unread messages in the inbox
  unread = gmail.inbox.count(:unread)
 
  #lets us know that we've checked the unread messages
  puts "Checked unread."
 
  #check if the number of unread messages has increased
  #if so, we have a new email! So, blink the LED.
  if unread > prev_unread
    port.write "b"
  end
 
  #reset the number of unread emails
  prev_unread = unread
 
  #wait before we make another request to the Gmail servers
  sleep wait_time
end