/// @description Insert description here
// You can write your code in this editor


if (instance_exists(oPlayer))
{
	var dir = point_direction(x, y, oPlayer.x, oPlayer.y);
	var dist = distance_to_object(oPlayer);
	if (dist < 400)
	{
		mp_potential_step_object(oPlayer.x, oPlayer.y, moveSpeed, oWall);
		image_angle = dir;
	}
}



if (hp <= 0)
{
	var inst = instance_create_layer(x, y, "Instances", oEnemyDead);
	inst.image_angle = image_angle;
	
	instance_destroy();
}