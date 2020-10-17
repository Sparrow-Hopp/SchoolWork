using UnityEngine;
using System.Collections;

public class FollowMouse : MonoBehaviour 
{

	public float offset;

	void Update () 
	{
		Follow ();
	}


	void Follow()
	{
		Vector3 mouseScreenPosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);

     	Vector3 lookAt = mouseScreenPosition;

     	float AngleRad = Mathf.Atan2(lookAt.y - this.transform.position.y, lookAt.x - this.transform.position.x) + offset;

     	float AngleDeg = (180 / Mathf.PI) * AngleRad;

     	this.transform.rotation = Quaternion.Euler(0, 0, AngleDeg);
	}
}
