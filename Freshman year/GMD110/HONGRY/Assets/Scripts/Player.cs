using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    Square target;
    bool isMoving = false, munch = false;
    public float speed = 20f;

    public static bool getMunch(Player p)
    {
        return p.munch;
    }
    public static bool getIsMoving(Player p)
    {
        return p.isMoving;
    }
    public void MovePlayer(Square square = null)
    {
        gameObject.transform.position = square.transform.position;
    }

    public void LerpPlayer(Square square = null)
    {
        if (isMoving == false)
        {
            GetComponent<Collider2D>().enabled = !GetComponent<Collider2D>().enabled;
            Debug.Log("Collider.enabled = " + GetComponent<Collider2D>().enabled);
            target = square;
            isMoving = true;
        }
        else if (isMoving == true)
        {
            
            transform.position = Vector2.MoveTowards(transform.position, target.transform.position, Time.deltaTime * speed);
            if (transform.position == target.transform.position)
            {                
                isMoving = false;
                GetComponent<Collider2D>().enabled = !GetComponent<Collider2D>().enabled;
                Debug.Log("Collider.enabled = " + GetComponent<Collider2D>().enabled);
            }
        }
    }

    void Update()
    {
        if (isMoving == true)
        {
            LerpPlayer();
        }
        munch = false;
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.tag != "Bounds" && col.gameObject.tag != "Square")
        {
            munch = true;
        }
    }

}