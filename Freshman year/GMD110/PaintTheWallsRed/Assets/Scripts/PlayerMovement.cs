using System;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    float xMove = 0f;
    public float xSpeed = 100f;
    Rigidbody2D myRigidbody2D;
    public float jumpForce = 7000f;
    bool isGrounded = false;
    bool shouldJump = false;
    public LayerMask ground;
    public Transform groundCheck;
    // Start is called before the first frame update
    void Start()
    {
        myRigidbody2D = gameObject.GetComponent<Rigidbody2D>();
    }

    void CheckInput()
    {
        xMove = Input.GetAxis("Horizontal") * xSpeed;
        if (Input.GetKeyDown(KeyCode.Space) && isGrounded)
        {
            shouldJump = true;
        }
    }

    void Move()
    {
        myRigidbody2D.velocity = new Vector2(xMove, myRigidbody2D.velocity.y);
    }

    void Update()
    {
        CheckInput();
    }

    void FixedUpdate()
    {
        Move();
        CheckJump();
        CheckGround();
    }

    void CheckJump()
    {
        if (shouldJump)
        {
            Jump();
        }
    }

    void Jump()
    {
        shouldJump = false;
        myRigidbody2D.AddForce(Vector2.up * jumpForce);
    }

    void CheckGround()
    {
        Collider2D col = Physics2D.OverlapCircle(groundCheck.position, 18f, ground);
        if (col == null)
        {
            isGrounded = false;
        }
        else
        {
            isGrounded = true;
        }
    }
    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "MovingPlatform")
        {
            transform.parent = collision.transform;
        }
        if (collision.gameObject.tag == "StickyGround")
        {
            Physics.gravity = new Vector3(0, -1.0F, 0);
            isGrounded = true;
        }
    }

    void OnCollisionExit2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "MovingPlatform")
        {
            transform.parent = null;
        }
        if (collision.gameObject.tag == "StickyGround")
        {
            Physics.gravity = new Vector3(0, -1.0F, 0);
            isGrounded = false;
        }
    }
}
