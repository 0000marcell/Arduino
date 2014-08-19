require "serialport"
port_str = '/dev/tty.usbmodemfa131'  #may be different for you
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE
sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)
wait_time = 1
loop do
	puts "Haja Luz!"
  sp.write "l"
  sleep wait_time
  puts "Apague a Luz!"
  sp.write "a"
  sleep wait_time
end