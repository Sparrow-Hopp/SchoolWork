using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollisionScript : MonoBehaviour
{
    // Start is called before the first frame update
    void OnCollisionEnter2D(Collision2D collision)
    {
        Debug.Log ("OnCollisionEnter2D");
    }

    void OnCollisionExit2D(Collision2D collision)
    {
        Debug.Log ("OnCollisionExit2D");
    }

    void OnCollisionStay2D(Collision2D collision)
    {
        Debug.Log ("OnCollisionStay2D");
    }
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
