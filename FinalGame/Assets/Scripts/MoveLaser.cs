using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveLaser : MonoBehaviour
{
    //public float offset;
    public float thrust;
    Vector3 mouseScreenPosition;
    Vector2 mouse;
    GameObject player;
    // Start is called before the first frame update
    void Start()
    {
        player = GameObject.Find ("Player");
        //float force = Mathf.Atan2(lookAt.y - this.transform.position.y, lookAt.x - this.transform.position.x) + offset;
        //float forceDir = (180 / Mathf.PI) * force;
        GetComponent<Rigidbody2D>().AddForce((mouseScreenPosition - player.transform.position) * thrust);
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        Destroy(gameObject);
    }
}