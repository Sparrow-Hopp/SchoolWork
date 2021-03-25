/// @description Insert description here
// You can write your code in this editor


var inst = instance_create_layer(x, y, "Instances", oPlayerDead);
inst.image_angle = image_angle;

oManager.alarm[0] = 120;

instance_destroy();