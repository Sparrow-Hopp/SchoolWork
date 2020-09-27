using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ship : MonoBehaviour
{

    public GameObject explosionPrefab;

    int damage = 0;

    void OnCollisionEnter2D(Collision2D collision)
    {
        Instantiate(explosionPrefab, transform.position, transform.rotation);

        GameManager.singleton.UpdateHealth(damage);

        //how and when might one have the Ship "blow up?" 
    }
}