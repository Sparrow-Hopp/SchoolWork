using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    Square target;
    bool isMoving = false;
    public float speed = 5f;

    public void MovePlayer(Square square = null)
    {
        gameObject.transform.position = square.transform.position;
    }

    public void LerpPlayer(Square square = null)
    {
        if (isMoving == false)
        {
            target = square;
            isMoving = true;
        }
        else if (isMoving == true)
        {
            transform.position = Vector2.MoveTowards(transform.position, target.transform.position, Time.deltaTime * speed);
            if (transform.position == target.transform.position)
            {
                isMoving = false;
            }
        }
    }

    void Update()
    {
        if (isMoving == true)
        {
            LerpPlayer();
        }
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.tag == "Junk")
        {
            GameManager.addTime(-3);
        }
        else if (col.gameObject.tag != "Square")
        {
            GameManager.addTime(3);
        }
    }
}