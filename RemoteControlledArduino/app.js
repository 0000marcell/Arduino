var five = require("johnny-five");
var myBoard, myLed;
var express = require('express');
var app = express();
var bodyParser = require('body-parser');

minhaplaca = new five.Board();

minhaplaca.on("ready", function() {
  meuled = new five.Led(13)
  //myLed.strobe( 1000 );
  // make myLED available as "led" in REPL
  // try "on", "off", "toggle", "strobe", "stop" (stops strobing)
  this.repl.inject({
    led: meuled
  });
  console.log("You can interact with the RGB LED via the variable 'led' e.g. led.on();\n Hit control-D to exit.\n >> ");
});

app.use(express.static('public'));
app.use(bodyParser());

app.post('/controlar', function (msg, res){
	console.log(msg.body);

	if(msg.body.msg == 'on'){
		meuled.on();	
	}

	if(msg.body.msg == 'off'){
		meuled.off();
	}
});

app.listen(3001, function () {
	console.log('Example app listening on port 3001!');
});
