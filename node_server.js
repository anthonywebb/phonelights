var net = require('net');
var serial = require('serialport');
var tempSerial, err;

var red = true;

try {
	tempSerial = new serial.SerialPort('/dev/tty.usbmodemfa141', {
		baudrate: 115200,
		parser: serial.parsers.readline("\n")
	});
} catch (e) {
	err = e;
}

if (!err) {
	found = tempSerial;
	console.log('info', 'Connected to arduino!');
	tempSerial.write('00000000');

	tempSerial.on("data", function (data) {
		console.log("got from arduino: "+data);
	});
}
else {
	console.log(err);
}

var tropoServer = net.createServer();
tropoServer.on('connection', function(client) {
	client.on('data', function(data) {
		if(data > 0 || data == 'end'){
			if(data == 'end') data = 0;
			console.log("got from tropo: "+data);
			tempSerial.write('!' + data + '.');
		}
	});
});

tropoServer.listen(7777);