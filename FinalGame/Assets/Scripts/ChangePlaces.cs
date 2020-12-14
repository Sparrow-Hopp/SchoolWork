using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangePlaces : MonoBehaviour
{
    GameObject player, up, down, left, right;
    float yMove, xMove;
    Rigidbody2D rb;
    public static int location;
    // Start is called before the first frame update
    void Start()
    {
        player = GameObject.Find("Player");
        rb = player.GetComponent<Rigidbody2D>();
        up = GameObject.Find("Up");
        down = GameObject.Find("Down");
        left = GameObject.Find("Left");
        right = GameObject.Find("Right");
    }

    // Update is called once per frame
    void Update()
    {
        yMove = rb.velocity.y;
        xMove = rb.velocity.x;
        checkVelocity();
    }

    void checkVelocity()
    {
        if (xMove > 0)
        {
            gameObject.transform.position = right.transform.position;
        }
        if (xMove < 0)
        {
            gameObject.transform.position = left.transform.position;
        }
        if (yMove > 0)
        {
            gameObject.transform.position = up.transform.position;
        }
        if (yMove < 0)
        {
            gameObject.transform.position = down.transform.position;
        }
    }
}
