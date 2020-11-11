using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAnimation : MonoBehaviour
{
    Rigidbody2D myRigidbody2D;
    Animator myAnimator;
    SpriteRenderer mySpriteRenderer;
    public Player player;
    //bool facingRight = true;
    bool isMoving;
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
        isMoving = Player.getIsMoving(player);
        CheckAnimation();
        //CheckFlip();
    }

    void CheckAnimation()
    {
        myAnimator.SetBool("isMoving", isMoving);
    }

    /*void CheckFlip()
    {
        if (facingRight && myRigidbody2D.velocity.x < -0.1)
        {
            Flip();
        }
        else if (!facingRight && myRigidbody2D.velocity.x > 0.1)
        {
            Flip();
        }
    }

    void Flip()
    {
        facingRight = !facingRight;
        mySpriteRenderer.flipX = !mySpriteRenderer.flipX;
    }*/
}
