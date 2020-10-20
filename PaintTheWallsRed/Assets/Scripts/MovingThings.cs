using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovingThings : MonoBehaviour
{
    public GameObject platform; //points to the platform prefab in the MovingPlatform
    //this is what will move, MovingPlatform just stays in position
    public float speed = 50f;// how fast the platform moves
    public Transform[] movePoints;// an array of points that the platform will follow
    Transform currentPoint;//the current point the platform is moving toward
    public int pointIndex = 0;//current index of the current platform
    public bool isLooping = true; //Loop the moving platform?
    // Start is called before the first frame update
    void Start()
    {
        currentPoint = movePoints[pointIndex];
    }

    // Update is called once per frame
    void Update()
    {
       platform.transform.position = Vector2.MoveTowards(platform.transform.position, currentPoint.position, Time.deltaTime * speed);

        if (platform.transform.position == currentPoint.position)
        {
            if (pointIndex < movePoints.Length - 1)
            {
                pointIndex++;
                currentPoint = movePoints[pointIndex];
                Debug.Log(pointIndex);
            }
            else if (isLooping == true)
            {
                pointIndex = 0;
                currentPoint = movePoints[pointIndex];
            }
        } 
    }
}

