﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerScript : MonoBehaviour
{
    // Start is called before the first frame update
    void OnTriggerEnter2D(Collider2D collider)
    {
        Debug.Log("OnTriggerEnter2D");
    }
    void OnTriggerExit2D(Collider2D collider)
    {
        Debug.Log ("OnTriggerExit2D");
    }
    void OnTriggerStay2D(Collider2D collider)
    {
        Debug.Log ("OnTriggerStay2D");
    }
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
