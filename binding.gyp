{
  'variables' : {
    'legacy':'<!(./version.js)',
  },
  "targets": [
    {
      "target_name": "pledge",
      "conditions" : [
        ["legacy=='yes'",
          {
            "sources": [ "pledge_10x.cc" ]
          },{
            "sources": [ "pledge.cc" ]
          }
        ]
      ],
    }
  ]
}
