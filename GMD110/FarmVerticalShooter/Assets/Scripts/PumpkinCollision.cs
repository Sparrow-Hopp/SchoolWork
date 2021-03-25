using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PumpkinCollision : MonoBehaviour
{
    void Start()
    {
        
    }
    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            Physics2D.IgnoreCollision(collision.gameObject.GetComponent<Collider2D>(), GetComponent<Collider2D>());//ignore collisions with player
        }
        if (collision.gameObject.tag == "Enemy")
        {
            gameObject.SetActive(false);
        }
    }
}
