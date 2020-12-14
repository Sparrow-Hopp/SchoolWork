using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnEnemies : MonoBehaviour
{
    public GameObject enemy;
    public float lowXBound, lowYBound, hiXBound, hiYBound;
    // Start is called before the first frame update
    void Start()
    {
        for (int i = 0; i < 5; i++)
        {
            Instantiate(enemy, new Vector3(Random.Range(lowXBound, hiXBound) + transform.position.x, Random.Range(lowYBound, hiYBound) + transform.position.y, 0), transform.rotation);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
