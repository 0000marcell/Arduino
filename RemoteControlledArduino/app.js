var five = require("johnny-five");
var myBoard, myLed;
var express = require('express');
var app = express();
var bodyParser = require('body-parser');

myBoard = new five.Board();

myBoard.on("ready", function() {
  myLed = new five.Led(13)
  //myLed.strobe( 1000 );
  // make myLED available as "led" in REPL
  // try "on", "off", "toggle", "strobe", "stop" (stops strobing)
  this.repl.inject({
    led: myLed
  });
  console.log("You can interact with the RGB LED via the variable 'led' e.g. led.on();\n Hit control-D to exit.\n >> ");
});

app.use(express.static('public'));
app.use(bodyParser());

app.post('/control-led', function (req, res){
	console.log(req.body);

	if(req.body.msg == 'on'){
		myLed.on();	
	}

	if(req.body.msg == 'off'){
		myLed.off();
	}
});

app.listen(3001, function () {
	console.log('Example app listening on port 3001!');
});
