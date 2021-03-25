/// @description Insert description here
// You can write your code in this editor

other.hp--;

var inst = instance_create_layer(x, y, "Instances", oPlayerBulletDead);
inst.image_angle = image_angle;

instance_destroy();