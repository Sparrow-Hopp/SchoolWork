using System;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    float xMove = 0f, yMove = 0f;
    public float xSpeed = 10f, ySpeed = 10f;
    Rigidbody2D myRigidbody2D;
    // Start is called before the first frame update
    void Start()
    {
        myRigidbody2D = gameObject.GetComponent<Rigidbody2D>();
    }

    void CheckInput()
    {
        xMove = Input.GetAxis("Horizontal") * xSpeed;
        yMove = Input.GetAxis("Vertical") * ySpeed;
    }

    void Move()
    {
        myRigidbody2D.velocity = new Vector2(xMove, yMove);
    }

    void Update()
    {
        CheckInput();
    }

    void FixedUpdate()
    {
        Move();
    }
}
