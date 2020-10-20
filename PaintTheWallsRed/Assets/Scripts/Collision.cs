using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collision : MonoBehaviour
{
    public GameObject ghost, sticky, rubber, reg;
    void OnCollisionEnter2D (Collision2D col)
    {
        if (col.gameObject.tag == "GhostPaint")
        {
            ghost.transform.localScale = this.transform.localScale;
            Instantiate(ghost, transform.position, transform.rotation);
            Destroy(gameObject);
        }
        else if (col.gameObject.tag == "StickyPaint")
        {
            sticky.transform.localScale = this.transform.localScale;
            Instantiate(sticky, transform.position, transform.rotation);
            Destroy(gameObject);
        }
        else if (col.gameObject.tag == "RubberPaint")
        {
            rubber.transform.localScale = this.transform.localScale;
            Instantiate(rubber, transform.position, transform.rotation);
            Destroy(gameObject);
        }
    }
}
