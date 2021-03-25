using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireLaser : MonoBehaviour
{
    public GameObject laserPrefab;
    Transform laserSpawn;

    void Start()
    {
        laserSpawn = transform.Find("LaserSpawn");
    }

    void Update()
    {
        CheckInput();
    }

    void CheckInput()
    {
        if (Input.GetMouseButtonDown(0))//use left mouse key to fire laser
        {
            Fire();
        }
    }

    void Fire()
    {
        GameObject laser = Instantiate(laserPrefab, laserSpawn.position, laserSpawn.rotation) as GameObject;//creates a laser object
    }
}