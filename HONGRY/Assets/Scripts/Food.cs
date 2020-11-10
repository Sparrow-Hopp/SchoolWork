using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Food : MonoBehaviour
{
    public static float speed = 5f;

    // Update is called once per frame
    void Update()
    {
        speed *= 1 + Time.time;
    }

    public static void move(GameObject food, int dir)
    {
        if (food.gameObject.tag == "Junk" || food.gameObject.tag == "Carrot")
        {
            float xMove = 0, yMove = 0;
            switch (dir)
            {
                case 1:
                    yMove = 1;
                    break;
                case 2:
                    xMove = 1;
                    yMove = 1;
                    break;
                case 3:
                    xMove = 1;
                    break;
                case 4:
                    xMove = 1;
                    yMove = -1;
                    break;
                case 5:
                    yMove = -1;
                    break;
                case 6:
                    xMove = -1;
                    yMove = -1;
                    break;
                case 7:
                    xMove = -1;
                    break;
                case 8:
                    xMove = -1;
                    yMove = 1;
                    break;
            }
            Vector2 direction = new Vector2 (xMove, yMove);
            food.GetComponent<Rigidbody2D>().AddForce(direction * speed);
        }
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.tag == "bounds")
        {
            if (this.gameObject.tag == "Junk");
            else
                GameManager.addTime(-2);
        }
    }
}
