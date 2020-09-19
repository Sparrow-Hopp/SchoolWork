using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveLaser : MonoBehaviour
{

    float laserLife = 60f;
    float lifeCount = 0f;

    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Rigidbody2D>().AddForce(transform.up * 500);
    }

    // Update is called once per frame
    void Update()
    {
        CheckLife();
    }

    void CheckLife()
    {
        lifeCount++;
        if (lifeCount == laserLife)
        {
            Destroy(gameObject);
        }
    }
}