using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveLaser : MonoBehaviour
{
    //public float offset;
    public float thrust;
    // Start is called before the first frame update
    void Start()
    {
        Vector3 mouseScreenPosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
     	Vector2 mouse = new Vector2 (mouseScreenPosition.x, mouseScreenPosition.y);
        //float force = Mathf.Atan2(lookAt.y - this.transform.position.y, lookAt.x - this.transform.position.x) + offset;
        //float forceDir = (180 / Mathf.PI) * force;
        GetComponent<Rigidbody2D>().AddForce(mouse * thrust);
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        Destroy(gameObject);
    }
}