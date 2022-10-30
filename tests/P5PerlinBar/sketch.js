var bars = []
var heightMult = 0.4
var nBars = 40; 
var marginMult = 0.003; 
var baseOffset = 0.3;

class Bar {
  constructor(rX,rY,W,mH,nO){
    this.rX = rX;
    this.rY = rY;
    this.W = W; 
    this.maxHeight = mH; 
    this.nO = nO;
  }
  
  resize(rX,rY,W,mH){
    this.rX = rX;
    this.rY = rY;
    this.W = W; 
    this.maxHeight = mH; 
  }
  
  draw(t){
    //console.log(width +" "+ this.rX + " " + this.rY)
    var N = noise(t,this.nO);
    var H = N * this.maxHeight;
    
    //console.log(N + " " + H  + " " + this.W );
    
    push();
    
    strokeWeight(1)
    colorMode(HSB,360,100,100,100);
    stroke(300 + 20 * N ,70 + 5 * N, 78 + 12 * N,62);
    fill(300 + 20* N, 10 + 10 * N, 78 +12 * N, 21);
      
    rect(this.rX,this.rY,-this.W, -H);
    
    pop();
  }
  
}

function setup() {
  createCanvas(windowWidth, windowHeight);
  
  var mH = heightMult * height
  var margin = marginMult * width
  var widthUnit = (width - (margin * (nBars + 1))) / (nBars -1);
  
  for(i = 0; i < nBars; i ++){
    var rX = (margin * (i+1)) + (widthUnit * i) 
    //var rX = widthUnit * i;
    var rY = height
    
    bars.push(new Bar( rX, rY, widthUnit, mH,  i * baseOffset));
  }
}

function draw() {
  clear();
  t = millis() / 200;
  
  for(i = 0; i < nBars; i ++){
    bars[i].draw(t);
  }
}

function windowResized(){
  resizeCanvas(windowWidth,windowHeight);
  
  
}


