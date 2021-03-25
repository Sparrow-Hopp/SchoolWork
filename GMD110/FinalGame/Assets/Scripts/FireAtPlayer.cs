using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireAtPlayer : MonoBehaviour
{
    public float wait, next;
    public GameObject laserPrefab;
    Transform laserSpawn;

    void Start()
    {
        laserSpawn = transform.Find("ThornSpawn");
    }

    // Update is called once per frame
    void Update()
    {
        if (Time.time > next)
        {
            next = Time.time + wait;//increasing the time until next spawn by however much the wait time is
            Fire();
        }
    }

    void Fire()
    {
        GameObject laser = Instantiate(laserPrefab, laserSpawn.position, laserSpawn.rotation) as GameObject;
    }
}
