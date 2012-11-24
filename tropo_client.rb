require 'socket' 
client = TCPSocket.new('node.mydomain.com', 7777)  
 
active_call = true
options = { :choices => '1,2,3,4,5,6,7,8,9,0' }
 
answer
sleep 1

say 'Press any key to change the color of my lights, press 0 to exit'

while active_call do
  result = ask '', options
  
  if result.value == '0'
    active_call = false
  else 
    client.puts result.value
    if result.value == '1'
      say "red"
    elsif result.value == '2'
      say 'green'
    elsif result.value == '3'
      say 'blue'
    elsif result.value == '4'
      say 'cyan'
    elsif result.value == '5'
      say 'magenta'
    elsif result.value == '6'
      say 'yellow'
    elsif result.value == '7'
      say 'purple'
    elsif result.value == '8'
      say 'orange'
    elsif result.value == '9'
      say 'white'
    end
  end
end
 
client.puts 'end'
say 'Merry Christmas, goodbye.'
 
client.close
hangup