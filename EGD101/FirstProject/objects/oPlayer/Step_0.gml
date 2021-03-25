/// @description Insert description here
// You can write your code in this editor

//Get Keyboard Input
left = keyboard_check(ord("A"));
right = keyboard_check(ord("D"));
down = keyboard_check(ord("S"));
up = keyboard_check(ord("W"));
fire = mouse_check_button(mb_left);


//Calculate Player Movement
hsp = (right - left) * moveSpeed;
vsp = (down - up) * moveSpeed;

//Mouse Aiming
dir = point_direction(x, y, mouse_x, mouse_y);
//image_angle = dir;

//shooting
if(fire)
{
	if (!hasShot)
	{
		hasShot = true;
		alarm[0] = coolDown;
		instance_create_layer(x, y, "Instances", oPlayerBullet);
		audio_play_sound(sndFire, 10, false);
	}
}

//Horizontal Collision Check
if (place_meeting(x + hsp, y, oWall))
{
	while (!place_meeting(x + sign(hsp), y, oWall))
	{
		x += sign(hsp)
	}
	hsp = 0;
}

//Vertical collision Check
if (place_meeting(x, y + vsp, oWall))
{
	while (!place_meeting(x, y + sign(vsp), oWall))
	{
		y += sign(vsp)
	}
	vsp = 0;
}


//Move the Player

x += hsp;
y += vsp;