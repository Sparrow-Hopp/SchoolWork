using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAnimation : MonoBehaviour
{
    Rigidbody2D myRigidbody2D;
    Animator myAnimator;
    SpriteRenderer mySpriteRenderer;
    bool facingRight = true;
    // Start is called before the first frame update
    void Start()
    {
       myRigidbody2D = GetComponent<Rigidbody2D>();
        myAnimator = gameObject.GetComponent<Animator>();
        mySpriteRenderer = GetComponent<SpriteRenderer>();
    }

    // Update is called once per frame
    void Update()
    {
        CheckAnimation();
        CheckFlipH();
    }

    void CheckAnimation()
    {
        myAnimator.SetFloat("xMove", Mathf.Abs(myRigidbody2D.velocity.x));
        myAnimator.SetFloat("yMove", myRigidbody2D.velocity.y);
    }

    void CheckFlipH()
    {
        if (facingRight && myRigidbody2D.velocity.x < -0.1)
        {
            FlipH();
        }
        else if (!facingRight && myRigidbody2D.velocity.x > 0.1)
        {
            FlipH();
        }
    }

    void FlipH()
    {
        facingRight = !facingRight;
        mySpriteRenderer.flipX = !mySpriteRenderer.flipX;
    }
}
