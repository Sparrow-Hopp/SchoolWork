/// @description Insert description here
// You can write your code in this editor


audio_play_sound(sndWall, 10, false);
var inst = instance_create_layer(x, y, "Instances", oPlayerBulletDead);
inst.image_angle = image_angle;

instance_destroy();