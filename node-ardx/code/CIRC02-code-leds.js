var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {
  var ledPins = [13, 12, 11, 10, 9, 8, 7, 6];
  var leds = new five.Leds(ledPins);

  function oneAfterAnother() {
    var delay = 1;
    board.counter = 0;
    for (var i = 0; i < leds.length; i++) {
      var led = leds[i];

      board.wait(delay,function(){
        console.log(this.counter + " on")
        leds[this.counter].on();
      })
      board.wait(delay + 200,function(){
        console.log(this.counter + " off")
        leds[this.counter].off();
        this.counter = (this.counter + 1) % leds.length;
      })
      delay += 500;
    }
  }

  // leds.on();
  // board.wait(1000, leds.off.bind(leds));

  oneAfterAnother();
  board.loop(4500, oneAfterAnother);
});
