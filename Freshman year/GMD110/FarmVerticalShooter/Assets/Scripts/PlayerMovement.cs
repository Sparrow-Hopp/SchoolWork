using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{

    float xMove = 10f;
    public float xSpeed = 10f;
    public float ySpeed = 5f;
    //float yMove = 10f;
    float boundsLeft = -2.1f;
    float boundsRight = 2.1f;
    float boundsUp = -2f;
    float boundsDown = -4.45f;
    public float jumpForce = 100f;
    Rigidbody2D rb;
    Rigidbody2D rigid;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        Rigidbody2D rigid = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        CheckInput();
    }
    void FixedUpdate()
    {
        Move();
        CheckBounds();
    }

    void CheckInput()
    {
        xMove = Input.GetAxis ("Horizontal") * xSpeed;//move left and right using a and d
        //yMove = Input.GetAxis ("Vertical") * ySpeed;//trying to figure out how to disable.. when all code is deleted player teleports to center of screen and won't load
    }

    void Move()
    {
        Vector2 newVelocity = new Vector2(xMove, 0);
        rb.AddForce(newVelocity);
        if(Input.GetKeyDown(KeyCode.Space))//allowing the player to jump by pressing space bar
        {
	        rb.AddForce(Vector2.up * jumpForce);
        }
    }

    void CheckBounds()
    {
    Vector2 maxPosX;
    Vector2 maxPosY;
         //Horizontal
        if (transform.position.x < boundsLeft)
        {
            maxPosX = new Vector2(boundsLeft, transform.position.y);
            transform.position = maxPosX;
        }
        else if (transform.position.x > boundsRight)
        {
            maxPosX = new Vector2(boundsRight, transform.position.y);
            transform.position = maxPosX;
        }
        //Vertical
        if (transform.position.y < boundsDown)
        {
            maxPosY = new Vector2(transform.position.x, boundsDown);
            transform.position = maxPosY;
        }
        else if (transform.position.y > boundsUp)
        {
            maxPosY = new Vector2(transform.position.x, boundsUp);
            transform.position = maxPosY;
        }
    }
}