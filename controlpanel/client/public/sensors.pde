Int width = 500;
Int height = 500;
Int width_offset = 250;
Int height_offset = 250;
Int led_radius = 90;

void setup() {

	background(255);
	size(700, 500);
}

void draw(){
	background(255);

	angle = 0;
	radius = 0;
	// inner ring
	for (int i = 0; i < 1; i = i+1) {
	    step = (2*Math.PI);
	    var x = width_offset + Math.round(width/2 + radius * Math.cos(angle) - width /2),
	        y = height_offset + Math.round(height/2 + radius * Math.sin(angle) - height	/2);

     	drawLed(i, x, y)
		
		angle += step;
	}

	// outer ring, 5 elements
	angle = 0;
	radius = 200;
	outer_elements = 7;

	for (int i = 1; i <= outer_elements; i = i+1) {
	    step = (2*Math.PI) / outer_elements;
	    var x = width_offset + Math.round(width/2 + radius * Math.cos(angle) - width /2),
	        y = height_offset + Math.round(height/2 + radius * Math.sin(angle) - height	/2);

     	drawLed(i, x, y)
		
		angle += step;
	}

	// inner ring
	angle = 0;
	radius = 100;
	inner_elements = 3;

	for (int i = outer_elements + 1; i <= outer_elements + inner_elements ; i = i+1) {
	    step = (2*Math.PI) / inner_elements;
	    var x = width_offset + Math.round(width/2 + radius * Math.cos(angle) - width /2),
	        y = height_offset + Math.round(height/2 + radius * Math.sin(angle) - height	/2);

     	drawLed(i, x, y)
		
		angle += step;
	}

}

String drawLed(index, x,y){
	if (sensors[index] == 1){
		fill(255,0,0);
	} else {
		fill(255,255,255);
	}
	stroke(0);
	ellipse(x, y, led_radius, led_radius);

	textSize(25);
	fill(0, 0, 0);
	textAlign(CENTER, CENTER);
	text(sensors[index], x, y);
}