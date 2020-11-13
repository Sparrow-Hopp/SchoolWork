using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Food : MonoBehaviour
{
    public static float speed = 0.1f;
    int dir;
    //float xDir = 0, yDir = 0;
    void Start()
    {
        dir = Random.Range(1, 8);//a random direction for the spawned enemy to move in
    }

    void Update()
    {
        move();//move the food
    }

    void move()
    {
        
        if (this.gameObject.tag == "Junk" || this.gameObject.tag == "Carrot")
        {
            float xMove = 0f, yMove = 0f;
            switch (dir)
            {
                case 1:
                    yMove = 1f;
                    break;
                case 2:
                    xMove = 1f;
                    yMove = 1f;
                    break;
                case 3:
                    xMove = 1f;
                    break;
                case 4:
                    xMove = 1f;
                    yMove = -1f;
                    break;
                case 5:
                    yMove = -1f;
                    break;
                case 6:
                    xMove = -1f;
                    yMove = -1f;
                    break;
                case 7:
                    xMove = -1f;
                    break;
                case 8:
                    xMove = -1f;
                    yMove = 1f;
                    break;
            }
            Vector2 direction = new Vector2(xMove, yMove);
            GetComponent<Rigidbody2D>().AddForce(direction * speed);
        }
        else if (this.gameObject.tag == "Tomato")//contents of this else if statement are taken from https://forum.unity.com/threads/make-object-move-in-an-expanding-spiral.47342/
        {
            float circleSpeed = 1;
            float circleSize = 1;
            float circleGrowSpeed = 0.1f;
 
            float xPos = Mathf.Sin(Time.time * circleSpeed) * circleSize;
            float yPos = Mathf.Cos(Time.time * circleSpeed) * circleSize;
 
            circleSize += circleGrowSpeed;

            Vector2 direction = new Vector2(xPos, yPos);
            GetComponent<Rigidbody2D>().AddForce(direction * speed);
        }
        else if (this.gameObject.tag == "Avocado")//same thing as previous else if statement except xPos and yPos are swapped
        {
            float circleSpeed = 1;
            float circleSize = 1;
            float circleGrowSpeed = 0.1f;
 
            float xPos = Mathf.Sin(Time.time * circleSpeed) * circleSize;
            float yPos = Mathf.Cos(Time.time * circleSpeed) * circleSize;
 
            circleSize += circleGrowSpeed;

            Vector2 direction = new Vector2(xPos, yPos);
            GetComponent<Rigidbody2D>().AddForce(direction * speed);
        }
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.tag != "Bounds" && col.gameObject.tag != "Player")
        {
            Debug.Log("Ignored");
            Physics2D.IgnoreCollision(col.gameObject.GetComponent<Collider2D>(), GetComponent<Collider2D>());//ignore collisions with other foods and regular squares
        }
        if (col.gameObject.tag == "Bounds")
        {
            if (this.gameObject.tag == "Junk");
            else
            {
                GameManager.addTime(-2);
            }
            Destroy(gameObject);
        }
        else if (col.gameObject.tag == "Player")
        {
            if (this.gameObject.tag == "Junk")
            {
                Debug.Log("JunkCollision");
                GameManager.addTime(-3);
                Food.addSpeed();
            }
            else
            {
                Debug.Log("HealthyCollision");
                GameManager.addTime(3);
                Food.addSpeed();
            }
            Destroy(this.gameObject);
        }
    }

    public static void addSpeed()
    {
        speed += 0.05f;
    }
}
