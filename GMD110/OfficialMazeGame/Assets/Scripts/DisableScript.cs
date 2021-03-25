using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DisableScript : MonoBehaviour
{
    public GameObject gameObj1;
    public GameObject gameObj2;
    // Start is called before the first frame update
    void OnTriggerEnter2D(Collider2D collider)
    {
        gameObj1.SetActive(false);
        gameObj2.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
