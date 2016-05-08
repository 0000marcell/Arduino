var five = require("johnny-five");
var myBoard, myLed;
var express = require('express');
var app = express();

myBoard = new five.Board();

myBoard.on("ready", function() {
  myLed = new five.Led(13)
  myLed.strobe( 1000 );
  // make myLED available as "led" in REPL
  // try "on", "off", "toggle", "strobe", "stop" (stops strobing)
  this.repl.inject({
    led: myLed
  });
  console.log("You can interact with the RGB LED via the variable 'led' e.g. led.on();\n Hit control-D to exit.\n >> ");
});

app.use(express.static('public'));

app.get('/', function (req, res) {
	res.send('hello world');
});

app.get('/user', function (req, res){
	res.send('User');	
});

app.listen(3001, function () {
	console.log('Example app listening on port 3001!');
});
